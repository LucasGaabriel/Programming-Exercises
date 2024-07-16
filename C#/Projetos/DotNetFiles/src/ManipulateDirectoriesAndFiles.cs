using System.IO;

class ManipulateDirectoriesAndFiles
{
    public static void Execute()
    {
        var newDir = Path.Combine(Directory.GetCurrentDirectory(), "stores","201","newDir");
        Directory.CreateDirectory(newDir);

        bool doesDirectoryExist = Directory.Exists(newDir);
        Console.WriteLine($"Does the directory exist? {doesDirectoryExist}");

        var currentDir = Directory.GetCurrentDirectory();
        var dir = Path.Combine(currentDir, "files");
        Directory.CreateDirectory(dir);
        File.WriteAllText(Path.Combine(dir, "greeting.txt"), "Hello World!");
    }
}