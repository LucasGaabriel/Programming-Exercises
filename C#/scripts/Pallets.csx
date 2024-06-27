string[] pallets = { "B14", "A11", "B12", "A13" };

Array.Sort(pallets);
Console.WriteLine("\nSorted:");
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Array.Reverse(pallets);
Console.WriteLine("\nReversed:");
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Console.WriteLine($"\nBefore: {pallets[0]}");
Array.Clear(pallets, 0, 2);
Console.WriteLine($"After: {pallets[0]}");

Console.WriteLine($"\nClearing 2 ... count: {pallets.Length}");
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Array.Resize(ref pallets, 6);
Console.WriteLine($"\nResizing 6 ... count: {pallets.Length}");

pallets[4] = "C01";
pallets[5] = "C02";

foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Array.Resize(ref pallets, 3);
Console.WriteLine($"\nResizing 3 ... count: {pallets.Length}");

foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}