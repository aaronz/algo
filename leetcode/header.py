import sys,urllib2
from datetime import datetime
from bs4 import BeautifulSoup

def get_desc(url):
	resp = urllib2.urlopen(url)
	content = resp.read()
	soup = BeautifulSoup(content, "lxml")
	desc = soup.select(".question-content")
	for d in desc:
		return d.get_text()

def prepend(file, header):
	with open(file, 'r+') as f:
		try:
			content = f.read()
			if not content.startswith('/* Problem:'):
				f.seek(0,0)
				f.write(header + '\n' + content)
			else:
				print 'header already added to ' + file + ', ignore'
		except UnicodeEncodeError:
			print 'UnicodeEncodeError'

def process_single(url):
	desc = get_desc(url)
	lines =  desc.split('\n')
	header = "/* Problem: {}\n* Author: Aaron Zhang\n* Date: {}\n".format(url, datetime.now().strftime("%d. %B %Y"))
	for l in lines:
		l = "* " + l
		header += l
		header +='\n'
	header += "*/\n"
	file = url.split('/')[-2]+'.cc'
	prepend(file, header)

def main():
	with open('index.txt','r') as index:
		urls = index.readlines()
		for url in urls:
			print 'processing ' + url
			process_single(url)

if __name__ == "__main__":main()
