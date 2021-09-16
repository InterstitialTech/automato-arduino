# use this to make the esp32 compiler work on nixos.
#   $ ./ns.sh
#   $ arduino
nix-shell https://github.com/nix-community/nix-environments/archive/master.tar.gz -A arduino
