using System;

namespace _02_maximum_pairwise_product
{
    class Program
    {
        private static long MaxPairwiseProduct(long[] numbers) {
            int n = numbers.Length;
            long first = 0;
            long second = 0;

            for (long x = 0; x < n; ++x) {
                if(numbers[x] >= first) {
                    second = first;
                    first = numbers[x];
                } else if(numbers[x] > second) {
                    second = numbers[x];
                }
            }

            return (first * second);
        }
        static void Main(string[] args)
        {
            var arrayNumber = int.Parse(Console.ReadLine());
            var input = Console.ReadLine();
            var tokens = input.Split(' ');
            long[] array = new long[arrayNumber];

            for(int i = 0; i < arrayNumber; i++){
                long x = long.Parse(tokens[i]);
                array[i] = x;
            }

            Console.WriteLine(MaxPairwiseProduct(array));
        }
    }
}
