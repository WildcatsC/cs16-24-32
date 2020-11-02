#!/bin/bash

recursive=false
GLOBIGNORE=.

isValidDir()
{
    if [[ ${#1} -gt 14 ]];
    then
        false
    elif [[ $1 =~ .*[^A-Za-z_.-].* ]];
    then
        false
    elif [[ $1 =~ ^\.{1,2}[^.]*$ ]];
    then
        false
    elif [[ $1 =~ ^-.*$ ]];
    then
        false
    else
        true
    fi
}

searchInvalidName()
{
    local search_path="$1"
    local filedata=`ls -aF $search_path`
    
    for file in $filedata
    do
        if [[ $file == "../" ]];
        then continue
        elif [[ $file == "./" ]];
        then continue
        fi

        if ! $2;
        then
            echo "$search_path/$file"
        elif [[ $file =~ ^.*\/$ ]];
        then
            echo "$search_path/$file"
            if $recursive;
            then
                local next_dir="$search_path/$file"
                local valid=$(isValidDir "${next_dir%?}")
                searchInvalidName "${next_dir%?}" $valid
            fi
        elif [[ ${#file} -gt 14 ]];
        then
            echo "$search_path/$file"
        elif [[ $file =~ .*[^A-Za-z_.-].* ]];
        then
            echo "$search_path/$file"
        elif [[ $file =~ ^\.{1,2}[^.]*$ ]];
        then
            echo "$search_path/$file"
        elif [[ $file =~ ^-.*$ ]];
        then
            echo "$search_path/$file"
        else
            for other in $filedata
            do
                if [[ "$file" == "$other" ]];
                then 
                    continue
                else
                    shopt -s nocasematch
                    if [[ "$file" == "$other" ]];
                    then
                        echo "$search_path/$file"
                        shopt -u nocasematch
                        break
                    fi
                    shopt -u nocasematch
                fi
            done
        fi
        
    done
}

dir=null
if (($# == 1))
then
    dir=$1
    if [ ! -d "$1" ];
    then
        echo "The specified directory does not exist." >&2
        exit 1
    fi
elif (($# == 2))
then
    dir=$2
    if [[ "$1" != "-r" ]]
    then
        echo "Invalid option." >&2
        exit 1
    else
        
        if [ ! -d "$2" ];
        then
            echo "The specified directory does not exist." >&2
            exit 1
        fi
        recursive=true
    fi
else
    echo "Invalid number of arguments." >&2
    exit 1
fi

dir_raw=$(echo $dir | tr "/" "\n")
dir_valid=true
for component in dir_raw
do
    if ! isValidDir $component;
    then $dir_valid=false
    fi
done
searchInvalidName $dir $dir_valid
