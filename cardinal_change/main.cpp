

#include <iostream> 

#include <string> 

using namespace std;

void test() {

    cout << "오류임\n";

}



string change(int t) {

    string temp;

    switch (t)

    {

    case 0:

        return "";

    case 1:

        return "I";

    case 5:

        return "V";

    case 10:

        return "X";

    case 50:

        return "L";

    case 100:

        return "C";

    case 500:

        return "D";

    case 1000:

        return "M";

    case 4:

        return "IV";

    case 9:

        return "IX";

    case 40:

        return "XL";

    case 90:

        return "XC";

    case 400:

        return "CD";

    case 900:

        return "CM";

    default:

        if (t / 10 == 0)//num 한자리수 

        {

            if (t > 5) { t -= 5; temp += change(5); }

            if (t % 3 == 1)temp += "I";

            if (t % 3 == 2)temp += "II";

            if (t % 3 == 0)temp += "III";

        }

        else if (t / 100 == 0)//num 두자리 수 

        {

            if (t > 50) { t -= 50; temp += change(50); }

            if ((t / 10) % 3 == 1)temp += "X";

            if ((t / 10) % 3 == 2 == 2) temp += "XX";

            if ((t / 10) % 3 == 0)temp += "XXX";

        }

        else if (t / 1000 == 0)

        {

            if (t > 500) { t -= 500; temp += change(50); }

            if ((t / 10) % 3 == 1) temp += "C";

            if ((t / 10) % 3 == 2) temp += "CC";

            if ((t / 10) % 3 == 0) temp += "CCC";



        }

        else if (t / 10000 == 0)

        {

            for (int i = 1; i <= (t / 1000); i++) {

                temp += "M";

            }



        }

    }



    return temp;

}



int main()

{



    string s;



    bool tr = true;

    bool str_int;

    int ttttt = 0;

    while (tr == true) {

        cout << "\n";



        cout << "입력할 숫자를 적어주세요. (1~3999)\n";



        cin >> s;



        str_int = (atoi(s.c_str()) != 0 || s.compare("0") == 0);

        //https://kamang-it.tistory.com/449 

        //0아닌지 확인, 문자열0인지 확인 

        if (str_int) {

            ttttt = std::stoi(s);



            if (ttttt < 4000 && ttttt>0) {

                string g = change(ttttt);

                cout << "로마숫자 변환:" + g + " \n";



            }

            else {

                test();

                tr = false;

            }

        }

        else {

            test();

        }











    }

    cout << "종료";



}







