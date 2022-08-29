rm -f ts;

FLAGS=" -Wall -Wextra -Werror "

c++ tst.cpp -std=c++20 -o ts;

./ts 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 21 22

./ts 1 2 3 4 5 6 7 8 9

rm -f ts;