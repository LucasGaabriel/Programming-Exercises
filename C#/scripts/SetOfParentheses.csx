string message = "(What if) there are (more than) one (set of parentheses)?";

while (true)
{
    int openingPosition = message.IndexOf('(');
    if (openingPosition == -1) break;
    int closingPosition = message.IndexOf(')');

    openingPosition += 1;

    int length = closingPosition - openingPosition;
    Console.WriteLine(message.Substring(openingPosition, length));

    message = message.Substring(closingPosition + 1);
}