class DirectoryAndEnvironment
{
    public static void Execute()
    {
        Console.WriteLine(Directory.GetCurrentDirectory());

        Console.WriteLine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments));

        Console.WriteLine($"stores{Path.DirectorySeparatorChar}201");

        Console.WriteLine(Path.Combine("stores","201"));

        Console.WriteLine(Path.GetExtension("sales.json"));

        string fileName = $"stores{Path.DirectorySeparatorChar}201{Path.DirectorySeparatorChar}sales{Path.DirectorySeparatorChar}sales.json";
        FileInfo info = new FileInfo(fileName);
        Console.WriteLine($"Full Name: {info.FullName}{Environment.NewLine}Directory: {info.Directory}{Environment.NewLine}Extension: {info.Extension}{Environment.NewLine}Create Date: {info.CreationTime}");
    }
}