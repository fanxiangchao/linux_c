/* Insert sort */
void insert_sort(int *array,int length)
{
    int i,j;
    for (i = 1; i < length; i++)
    {
        int temp;
        j = i;
        temp = array[j];
        while( j > 0)
        {
            if (temp < array[j - 1])
            {
                array[j] = array[j - 1];
                j--;
            }
            else
            {
                break;
            }
        }
        array[j] = temp;
    }
}

/* binary search */
int binary_search(int *array,int item,int length)
{
    int high,low,mid;
    high = length - 1;
    low = 0;
    mid = (high + low) / 2;

    while (low < high)
    {
        if (array[mid] > item)
        {
            high = mid;
            mid = (high + low) / 2;
        }
        else if (array[mid] < item)
        {
            low = mid;
            if ((high + low) % 2 == 0)
            {
                mid = (high + low) / 2;
            }
            else
            {
                mid = (high + low) / 2 + 1;
            }
            
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

/* bubble sort */
void bubble_sort(int *array,int length)
{
    int i,j;
    int exchange;
    int temp;
    i = 0;
    exchange = 1;

    while (i < length && exchange)
    {
        j = length - 1;
        exchange = 0;
        while (j >= i)
        {
            if (array[j] < array[j - 1])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                exchange = 1;
            }
            j--;
        }
        i++;
    }
}