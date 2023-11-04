using System;

namespace Lab9
{   
    class Client
    {
        public string[] List_of_buy;

        public void Want_List()
        {
            Console.WriteLine("Ask client: \"What are you willing to buy?:\" ");
            string Wants = Console.ReadLine();
            List_of_buy = Wants.Split(", ");
        }

        public void Print_List()
        {
            foreach (string it in List_of_buy)
            {
                Console.Write(it);
            }
            Console.WriteLine();
        }

        public Client()
        {
            Want_List();
        }
    }
}
