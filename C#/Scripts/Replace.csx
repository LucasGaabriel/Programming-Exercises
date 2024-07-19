string message = "This--is--ex-amp-le--da-ta";

message = message.Replace("--", " ");
message = message.Replace("-", "");

Console.WriteLine(message);