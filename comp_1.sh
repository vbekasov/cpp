echo '!!!!NEW!!!!'

FLAGS=" -Wall -Wextra -Werror "

rm -f bitr; g++ bits.cpp -std=c++20 $FLAGS -o bitr ; ./bitr