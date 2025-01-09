// Source : HackerRank

int chocolateFeast(int n, int c, int m)
{
    int eat = 0;
    int wrappers = n / c;
    eat = wrappers;

    while (wrappers >= m)
    {
        int newChoc = wrappers / m;
        eat += newChoc;
        wrappers = wrappers % m + newChoc;
    }

    return eat;
}
