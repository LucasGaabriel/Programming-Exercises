class RandomDice
{
    public static void Random()
    {
        Random dice = new Random();
        int roll = dice.Next(1, 7);
        Console.WriteLine(roll);
    }
}