using System;
using System.Collections.Generic;

namespace algorithm
{
    public class Combination
    {
        public static IEnumerable<int[]> Combinations(int m, int n)
        {
            int[] result = new int[m];
            Stack<int> stack = new Stack<int>();
            stack.Push(0);

            while (stack.Count > 0)
            {
                int index = stack.Count - 1;
                int value = stack.Pop();
                while (value < n)
                {
#if DEBUG
                    Console.WriteLine("index {0} value {1}", index, value);
#endif
                    result[index++] = value++;
#if DEBUG
                    for (int i = 0; i < result.Length; i++)
                    {
                        Console.Write(result[i] + " ");
                    }
                    Console.WriteLine();
#endif
                    if (value < n)
                    {
#if DEBUG
                        Console.WriteLine("Stack Push value: {0}", value);
#endif
                        stack.Push(value);
                    }
                    if (index == m)
                    {
                        yield return result;
                        break;
                    }
                }
            }
        }

        public static void Main()
        {
            foreach (int[] c in Combinations(3, 5))
            {
#if DEBUG
                Console.Write(">>>");
#endif
                for (int i = 0; i < c.Length; i++)
                {
                    Console.Write(c[i] + " ");
                }
                Console.WriteLine();
            }
            Console.Read();
        }
    }
}
