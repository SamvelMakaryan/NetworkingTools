#!/bin/bash

print_message() {
  local message="$1"
  echo -e "\e[1m\e[33m$message\e[0m"
}

print_message "🌐 Welcome to the Network Connectivity Check! 🌐"

check_connectivity() {
  local host="$1"

  ping -c 4 -W 1 "$host" &>/dev/null

  if [ $? -eq 0 ]; then
    echo "Network connectivity to $host is UP."
  else
    echo "Network connectivity to $host is DOWN."
  fi
}

echo -n "Enter the hostname or IP address to check connectivity: "
read remote_host

check_connectivity "$remote_host"

print_message "👋  Goodbye! 👋"

