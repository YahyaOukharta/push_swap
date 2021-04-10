if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    entries=($(shuf -i 0-20 -n 5))
    ARG="${entries[@]}"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    ARG=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')" 2> /dev/null);
fi

echo $ARG;
