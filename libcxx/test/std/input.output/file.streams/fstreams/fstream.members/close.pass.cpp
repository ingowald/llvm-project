//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_fstream

// void close();

#include <fstream>
#include <cassert>
#include "platform_support.h"

int main(int, char**)
{
    std::string temp = get_temp_file_name();
    {
        std::fstream fs;
        assert(!fs.is_open());
        fs.open(temp.c_str(), std::ios_base::out);
        assert(fs.is_open());
        fs.close();
        assert(!fs.is_open());
    }
    std::remove(temp.c_str());
    {
        std::wfstream fs;
        assert(!fs.is_open());
        fs.open(temp.c_str(), std::ios_base::out);
        assert(fs.is_open());
        fs.close();
        assert(!fs.is_open());
    }
    std::remove(temp.c_str());

  return 0;
}
