



public static void Binary_search(string[] array,string target)
    {
        int lower = 0;
        int upper = array.Length-1;
        int mid = 0;
        int compare = 0;

        while(lower <= upper)
        {
            mid = (lower + upper) / 2;
            compare = string.Compare(array[mid],target);

            if(array[mid].StartsWith(target))
            {
                Console.WriteLine(array[mid]);
                break;
            }
            else if(compare > 0)
            {
                upper = mid+1;
            }
            else if(compare < 0)
            {
                lower = mid-1;
            }
        }
    }