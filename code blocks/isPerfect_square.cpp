int isPerfectSquare(long long int n)
{
    long long int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
        return 0;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        long long int t = (long long int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}

