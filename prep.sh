#!/usr/bin/env bash
mkdir -p ./data/employees
mkdir -p ./data/counters
if [[ ! -e ./data/counters/employees ]]; then
    touch ./data/counters/employees
    echo "0" > ./data/counters/employees
fi