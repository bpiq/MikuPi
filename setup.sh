#!/bin/bash
# by MikuQ(i@mikuq.com) 2017-1-6

{
    for ((i = 0 ; i <= 100 ; i+=1)); do
        sleep 0.01
        echo $i
    done
    sleep 0.5
} | whiptail --gauge "正在加载MikuDuino配置工具" 6 60 0

if [ "$(id -u)" -ne 0 ]; then
    whiptail --title "错误" --msgbox "配置工具需要ROOT权限" --ok-button "离开" 10 60
    echo
    echo -e "\033[31m 需要ROOT权限 \033[0m"
    echo
    exit 1
fi

menu()
{
    OPTION=$(whiptail --title "MikuDuino配置工具 V0.8" --menu "\n选择需要的配置项" 15 60 4 "1" "编译MikuDuino" "2" "设置开发板" "3" "安装MikuDuino" "4" "退出配置工具" --ok-button "确定" --cancel-button "离开"  3>&1 1>&2 2>&3)
    exitstatus=$?
    if [ $exitstatus = 0 ]; then
        case $OPTION in
            1) make;;
            2) echo "设置";;
            3) make install;;
            4) echo
               echo -e "\033[32m 技术参考 https://help.mikuduino.com/ \033[0m"
               echo
               exit 0;;
        esac
    else
        echo
        echo -e "\033[32m 技术资料 https://help.mikuduino.com/ \033[0m"
        echo
    fi
}

while true
do
    menu
done

