#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;
char res[4] , colors[6] = { 'P' , 'Y' , 'B' , 'O' , 'R' , 'G' } ;
void setResult (void)
{
    srand(time(0));
    const int ARRAY_SIZE = 4;
    int randomNumbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        bool isUnique = false;
        while (!isUnique) {
            int randomNumber = rand() % 7;
            isUnique = true;
            for (int j = 0; j < i; j++) {
                if (randomNumbers[j] == randomNumber) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                randomNumbers[i] = randomNumber;
            }
        }
    }
    for (int i = 0 ; i < 4 ; i++ )
    {
        res[i] = randomNumbers[i] ;
        res[i] = colors[res[i]] ;
    }

}
bool isTrue(char a , char b , char c , char d )
{
    bool state = false ;
    char pos[4] ;
    int black = 0 , white = 0  ;
    pos[0] = a ;
    pos[1] = b ;
    pos[2] = c ;
    pos[3] = d ;
    for (int i = 0 ; i < 4 ; i++ )
    {
        if (res[i] == pos[i])
        {
            black++ ;
            pos[i] = ' ' ;
        }
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int c = 0 ; c < 4 ; c++)
        {
            if (res[i] == pos[c] && pos[c] != ' ')
            {
                white++ ;
            }
        }
    }
    if (black == 4 )
    {
        cout << "------------!!! YOU WON !!!------------\n" ;
        state = true ;
    }
    else
    {
        cout << "Nice Try !! \n" ;
        cout << "You Got :" << black << "Black Points. \n" ;
        cout << "You Got :" << white << "White Points. \n" ;
        cout << endl << endl << endl ;
        state = false ;
    }
    return state ;

}
int main ()
{
    char a , b , c , d ;
    bool s ;
    int x = 0 ;
    cout << "------------WELCOME TO MASTER MIND GAME------------\n" ;
    Main :
    setResult() ;
    cout << endl << endl << endl ;
    cout << "Colors You Have : \n" ;
    cout << "1.Purple\t" << "P\n" ;
    cout << "2.Yellow\t" << "Y\n" ;
    cout << "3.Blue\t"<< "\t" << "B\n" ;
    cout << "4.Orange\t" << "O\n" ;
    cout << "5.Red\t" << "\t"<< "R\n" ;
    cout << "6.Green\t" << "\t"<< "G\n" ;
    cout << "You Have 7 Tries To Concluode The True Combination of The Colors \n" ;
    cout << "\nNOTE : Odds Must Be Entered As Upper Case Letters " << endl ;
    for ( int i = 0 ; i < 7 ; i++)
    {
        cout << "Try No." << i+1 << ": \n" ;
        cout << "Enter Your Odds : \n" ;
        cin >> a >> b >> c >> d ;
        s = isTrue ( a , b , c , d ) ;
        if (s == true)
        {
            cout << endl << endl << endl ;
            goto Main ;
        }
    }
    if ( s == false )
    {
        cout << "------------!!!OUT OF TRIES!!!------------\n" ;
        cout << "Combination Was : " ;
        for (int i = 0 ; i < 4 ; i++ )
        {
            cout << res[i] << "\t" ;
        }
        cout << endl << endl << endl << endl ;
        goto Main ;
    }
}

