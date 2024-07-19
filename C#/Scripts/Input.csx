#nullable enable

string? readResult;

Console.WriteLine("Enter a string:");

do
{
    readResult = Console.ReadLine();
} while (readResult == null);

Console.WriteLine($"Read Result = {readResult}");