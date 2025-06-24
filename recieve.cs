using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        // Set up the TCP listener on localhost and port 8888
        TcpListener listener = new TcpListener(IPAddress.Parse("127.0.0.1"), 8888);
        listener.Start();
        
        Console.WriteLine("Waiting for a connection...");

        // Accept the client connection
        TcpClient client = listener.AcceptTcpClient();
        Console.WriteLine("Connected!");

        NetworkStream stream = client.GetStream();

        while (true)
        {
            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);

            if (bytesRead == 0)
            {
                break;
            }

            string data = Encoding.UTF8.GetString(buffer, 0, bytesRead);
            Console.WriteLine($"Received: {data}");
        }

        client.Close();
        listener.Stop();
    }
}