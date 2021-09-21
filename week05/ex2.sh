#!bin/bash
if [[ ! -f "ex2.txt" ]]; then
    echo "1" > "ex2.txt"
fi

while true; do
    if ln "ex2.txt" "ex2.lock" 2> /tmp/ex2.txt ; then
        a=$(cat "ex2.txt" | tail -n 1)
        echo "$((a + 1))" >> ex2.txt
        rm "ex2.lock"
    fi
done
rm /tmp/ex2.txt 