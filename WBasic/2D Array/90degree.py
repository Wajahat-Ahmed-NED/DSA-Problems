# does not work
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        
        # int row=matrix.size();
        row=len(matrix)
        col=len(matrix[0])
        # int col=matrix[0].size();
        # cout<<row<<endl;
        # vector<int> firstR/ow=matrix[0];
        firstRow=matrix[0]
        print(firstRow)
        count=row;
        total=row*col;
        arrInd=1

        startingCol=0;
        startingRow=1;
        endingCol=col-1;
        endingRow=row-1;
        # firstRow=matrix[0]

        while(count<total):
           
            # //traverse ending col
            if(count<total):

                for ind in range(startingRow,endingRow+1):
                    firstRow.append(matrix[ind][endingCol]);
                    matrix[ind][endingCol]=firstRow[arrInd];
                    count+=1
                    arrInd+=1
                
                endingCol-=1

                # print("matrix",matrix)
                # print("firstRow",firstRow)
                # break;
                print("matrix",matrix)
            print(count)
            if(count<total):

                # //traverse ending row
                for ind in range(endingCol,startingCol-1,-1):
                    firstRow.append(matrix[endingRow][ind]);
                    matrix[endingRow][ind]=firstRow[arrInd];
                    count+=1;
                    arrInd+=1
                
                endingRow-=1;
                print("matrix",matrix)
            if(count<total):

                # //traverse starting col
                for ind in range(endingRow,startingRow-1,-1):  
                    firstRow.append(matrix[ind][startingCol]);
                    matrix[ind][startingCol]=firstRow[arrInd];
                    count+=1;
                    arrInd+=1
                
                startingCol+=1;
                print("matrix",matrix)
            if(count<total):

                # //traverse starting row
                for ind in range(startingCol,endingCol+1):
                    firstRow.append(matrix[startingRow][ind]);
                    matrix[startingRow][ind]=firstRow[arrInd];
                    count+=1;
                    arrInd+=1
                
                startingRow+=1;
                print("matrix",matrix)

        print("firstRow",firstRow)
        print(matrix)
        
        
    