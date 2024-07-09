const string input = "<div><h2>Widgets &trade;</h2><span>5000</span></div>";

string quantity = "";
string output = "";

const string openSpan = "<span>";
const string closeSpan = "</span>";

int quantityStart = input.IndexOf(openSpan) + openSpan.Length; // + length of <span> so index at end of <span> tag
int quantityEnd= input.IndexOf(closeSpan);

int quantityLength = quantityEnd - quantityStart;
quantity = input.Substring(quantityStart, quantityLength);
quantity = $"Quantity: {quantity}";

const string tradeSymbol = "&trade;";
const string regSymbol = "&reg;";
output = input.Replace(tradeSymbol, regSymbol);

const string openDiv = "<div>";
const string closeDiv = "</div>";

int divStart = output.IndexOf(openDiv);
output = output.Remove(divStart, openDiv.Length);

int divCloseStart = output.IndexOf(closeDiv);
output = "Output: " + output.Remove(divCloseStart, closeDiv.Length);

Console.WriteLine(quantity);
Console.WriteLine(output);