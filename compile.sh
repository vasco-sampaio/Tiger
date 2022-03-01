if [ "$#" -ne 0 ]; then
    echo "Usage: ./compile.sh"
    exit 1
fi

libtoolize
./bootstrap
./configure CXXFLAGS='-std=c++20 -O0 -g -fno-inline -Werror -Wall -Wextra -pedantic'
make -j4
