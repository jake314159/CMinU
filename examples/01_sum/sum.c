
int my_sum(int array[], int length)
{
    int i;
    int sum = 0;
    for(i=0; i<length; i++) {
        sum += array[i];
    }
    return sum;
}
