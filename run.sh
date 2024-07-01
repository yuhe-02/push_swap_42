#!/bin/bash

# 順列を生成する関数
function generate_permutations {
    local items=("$@")
    local perm_list=()
    local -i count=0

    # 5要素の全ての順列を生成
    while read -ra perm; do
        perm_list+=("${perm[@]}")
        ((count++))
    done < <(echo "${items[@]}" | tr ' ' '\n' | awk 'BEGIN { RS=" " } { print $1 }' | \
             awk 'BEGIN { OFS=" " } { for (i = 1; i <= NF; i++) print $i }' | \
             sort -u | \
             perl -MAlgorithm::Permute -lane 'Algorithm::Permute::permute { print "@F" } @F')

    # 生成した順列を./push_swapに渡して実行
    for perm in "${perm_list[@]}"; do
        ./push_swap "${perm[@]}"
    done
}

# メインスクリプトの処理
if [ "$#" -ne 5 ]; then
    echo "Usage: $0 <num1> <num2> <num3> <num4> <num5>"
    exit 1
fi

# 引数を配列に格納
numbers=("$@")

# 順列を生成して./push_swapに渡す
generate_permutations "${numbers[@]}"

