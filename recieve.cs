using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        UdpClient udpClient = new UdpClient(8888);
        IPEndPoint remoteEP = new IPEndPoint(IPAddress.Any, 0);

        Console.WriteLine("Waiting for a connection...");

        while (true)
        {
            byte[] receiveBytes = udpClient.Receive(ref remoteEP);
            string receivedData = Encoding.UTF8.GetString(receiveBytes);

            Console.WriteLine($"Received: {receivedData}");
        }
    }
}