using System.IO;
using System.Collections.Generic;
using Newtonsoft.Json;

class SalesTotal
{
    public double Total { get; set; }
}

record SalesData (double Total);

class Program
{
    public static void Main()
    {
        var currentDirectory = Directory.GetCurrentDirectory();
        var storesDirectory = Path.Combine(currentDirectory, "stores");

        var salesTotalDir = Path.Combine(currentDirectory, "salesTotalDir");
        Directory.CreateDirectory(salesTotalDir);

        var salesFiles = FindFiles(storesDirectory);

        var fileTotals = Path.Combine(salesTotalDir, "totals.txt");
        if (!File.Exists(fileTotals)){
            File.WriteAllText(fileTotals, String.Empty);
        }

        var salesTotal = CalculateSalesTotal(salesFiles);

        var salesJson = File.ReadAllText($"stores{Path.DirectorySeparatorChar}201{Path.DirectorySeparatorChar}sales.json");
        var salesData = JsonConvert.DeserializeObject<SalesTotal>(salesJson);

        if (salesData is not null){
            Console.WriteLine(salesData.Total);
        }

        var data = JsonConvert.DeserializeObject<SalesTotal>(salesJson);

        if (data is not null)
        {
            File.AppendAllText(Path.Combine(salesTotalDir, "totals.txt"), $"{salesTotal}{Environment.NewLine}");
        }

        IEnumerable<string> FindFiles(string folderName)
        {
            List<string> salesFiles = new List<string>();

            var foundFiles = Directory.EnumerateFiles(folderName, "*", SearchOption.AllDirectories);

            foreach (var file in foundFiles)
            {
                var extension = Path.GetExtension(file);

                if (extension == ".json")
                {
                    salesFiles.Add(file);
                }
            }

            return salesFiles;
        }

        double CalculateSalesTotal(IEnumerable<string> salesFiles)
        {
            double salesTotal = 0;

            foreach (var file in salesFiles)
            {      
                // Read the contents of the file
                string salesJson = File.ReadAllText(file);

                // Parse the contents as JSON
                SalesData? data = JsonConvert.DeserializeObject<SalesData?>(salesJson);

                // Add the amount found in the Total field to the salesTotal variable
                salesTotal += data?.Total ?? 0;
            }

            return salesTotal;
        }

        Console.WriteLine("\n-----\n");

        DirectoryAndEnvironment.Execute();

        Console.WriteLine("\n-----\n");

        ManipulateDirectoriesAndFiles.Execute();
    }
}