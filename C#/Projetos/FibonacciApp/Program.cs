using System;

class FibonacciSequence
{
    static void Main(string[] args)
    {
        // Check if an argument is provided
        if (args.Length < 1)
        {
            Console.WriteLine("Please provide the number of elements as an argument.");
            return;
        }

        // Try to parse the argument to an integer
        if (!int.TryParse(args[0], out int numberOfElements))
        {
            Console.WriteLine("Please provide a valid integer as the number of elements.");
            return;
        }

        // Initialize the memoization array
        long[] memo = new long[numberOfElements];
        for (int i = 0; i < numberOfElements; i++)
        {
            Console.WriteLine(Fibonacci(i, memo));
        }
    }

    // Method to calculate Fibonacci number using memoization
    static long Fibonacci(int n, long[] memo)
    {
        if (n <= 1)
            return n;
        if (memo[n - 1] != 0)
            return memo[n - 1];
        else
        {
            memo[n - 1] = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
            return memo[n - 1];
        }
    }
}