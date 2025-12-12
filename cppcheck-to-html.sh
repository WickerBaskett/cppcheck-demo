#!/bin/bash
mkdir -p out
cppcheck --enable=warning --xml template.cpp 2> xml.out
cppcheck-htmlreport --file=xml.out --report-dir=out
cd out
python3 -m http.server 8080
