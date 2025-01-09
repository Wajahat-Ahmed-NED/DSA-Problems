// Source: Hacker Rank

int truckTour(vector<vector<int>> petrolpumps)
{

    long totalPetrol = 0;
    long totalDistance = 0;
    long currentPetrol = 0;
    int i = 0;
    int startInd = 0;

    while (i < petrolpumps.size())
    {
        totalPetrol += petrolpumps[i][0];
        totalDistance += petrolpumps[i][1];
        currentPetrol += petrolpumps[i][0] - petrolpumps[i][1];

        if (currentPetrol < 0)
        {
            startInd = i + 1;
            currentPetrol = 0;
        }

        i++;
    }

    if (totalPetrol < totalDistance)
    {
        return -1;
    }

    return startInd;
}
