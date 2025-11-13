#!/bin/bash
# cpp1 packaging script (English version)
# Usage: ./package_en.sh [options]
# Options:
#   --all        Package every file (including build artifacts)
#   --clean      Package only essential files (binary, headers, library, Makefile)
#   --release    Package release bundle (default, essential files only)
#   --standalone Package a self-contained bundle including Verilator headers

set -e

# Determine the directory where this script resides
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Default mode
PACKAGE_MODE="release"
PACKAGE_NAME="cpp1"

# Parse command line arguments
if [ "$1" == "--all" ]; then
    PACKAGE_MODE="all"
    PACKAGE_NAME="cpp1-all"
elif [ "$1" == "--clean" ]; then
    PACKAGE_MODE="clean"
    PACKAGE_NAME="cpp1-clean"
elif [ "$1" == "--standalone" ]; then
    PACKAGE_MODE="standalone"
    PACKAGE_NAME="cpp1-standalone"
elif [ "$1" == "--release" ] || [ -z "$1" ]; then
    PACKAGE_MODE="release"
    PACKAGE_NAME="cpp1-release"
else
    echo "Usage: $0 [--all|--clean|--release|--standalone]"
    echo "  --all        Package every file (includes intermediate build files)"
    echo "  --clean      Package essential files only"
    echo "  --release    Package release bundle (default)"
    echo "  --standalone Package bundle with Verilator headers"
    exit 1
fi

# Create a temporary packaging directory
TEMP_DIR=$(mktemp -d)
PACKAGE_DIR="$TEMP_DIR/$PACKAGE_NAME"
mkdir -p "$PACKAGE_DIR"

echo "Packaging cpp1 (mode: $PACKAGE_MODE)..."

# Copy essential files (applies to every mode)
echo "Copying essential files..."
cp -v Vtoplevel.mk "$PACKAGE_DIR/" 2>/dev/null || true
cp -v Vtoplevel_classes.mk "$PACKAGE_DIR/" 2>/dev/null || true
cp -v Vtoplevel__verFiles.dat "$PACKAGE_DIR/" 2>/dev/null || true

# Copy headers
echo "Copying header files..."
cp -v *.h "$PACKAGE_DIR/" 2>/dev/null || true

# Copy static library
echo "Copying static library..."
cp -v Vtoplevel__ALL.a "$PACKAGE_DIR/" 2>/dev/null || true

# Copy executable if present
if [ -f "Vtoplevel" ]; then
    echo "Copying executable..."
    cp -v Vtoplevel "$PACKAGE_DIR/"
    chmod +x "$PACKAGE_DIR/Vtoplevel"
fi

# Copy additional files depending on the mode
if [ "$PACKAGE_MODE" == "all" ]; then
    echo "Copying every file (including intermediates)..."
    cp -v *.cpp "$PACKAGE_DIR/" 2>/dev/null || true
    cp -v *.o "$PACKAGE_DIR/" 2>/dev/null || true
    cp -v *.d "$PACKAGE_DIR/" 2>/dev/null || true
    cp -v *.txt "$PACKAGE_DIR/" 2>/dev/null || true
else
    echo "Copying source files (excluding intermediates)..."
    cp -v *.cpp "$PACKAGE_DIR/" 2>/dev/null || true
fi

# Handle standalone mode: include Verilator headers
HAS_VERILATOR_HEADERS=false
if [ "$PACKAGE_MODE" == "standalone" ]; then
    echo "Locating Verilator installation..."

    # Determine candidate Verilator root
    VERILATOR_ROOT_CANDIDATE=""

    # 1. Environment variable
    if [ -n "${VERILATOR_ROOT}" ] && [ -d "${VERILATOR_ROOT}" ]; then
        VERILATOR_ROOT_CANDIDATE="${VERILATOR_ROOT}"
    # 2. Value from Makefile
    elif [ -f "Vtoplevel.mk" ]; then
        VERILATOR_ROOT_CANDIDATE=$(grep "^VERILATOR_ROOT" Vtoplevel.mk | head -1 | sed 's/.*=\s*//' | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    fi

    # 3. Fallback to common paths if still empty
    if [ -z "$VERILATOR_ROOT_CANDIDATE" ]; then
        for path in "/usr/local/share/verilator" "/usr/share/verilator"; do
            if [ -d "$path" ]; then
                VERILATOR_ROOT_CANDIDATE="$path"
                break
            fi
        done
    fi

    if [ -n "$VERILATOR_ROOT_CANDIDATE" ] && [ -d "$VERILATOR_ROOT_CANDIDATE/include" ]; then
        echo "Verilator found at: $VERILATOR_ROOT_CANDIDATE"
        echo "Copying Verilator headers..."

        VERILATOR_INCLUDE_DIR="$PACKAGE_DIR/verilator_include"
        mkdir -p "$VERILATOR_INCLUDE_DIR"

        HEADER_COUNT=0
        CPP_COUNT=0

        # Copy header files
        while IFS= read -r header_file; do
            rel_path="${header_file#$VERILATOR_ROOT_CANDIDATE/include/}"
            dest_path="$VERILATOR_INCLUDE_DIR/$rel_path"
            mkdir -p "$(dirname "$dest_path")"
            if cp "$header_file" "$dest_path" 2>/dev/null; then
                HEADER_COUNT=$((HEADER_COUNT + 1))
            fi
        done < <(find "$VERILATOR_ROOT_CANDIDATE/include" -name "*.h" -type f)

        # Copy support .cpp files (needed by standalone builds)
        while IFS= read -r cpp_file; do
            rel_path="${cpp_file#$VERILATOR_ROOT_CANDIDATE/include/}"
            dest_path="$VERILATOR_INCLUDE_DIR/$rel_path"
            mkdir -p "$(dirname "$dest_path")"
            if cp "$cpp_file" "$dest_path" 2>/dev/null; then
                CPP_COUNT=$((CPP_COUNT + 1))
            fi
        done < <(find "$VERILATOR_ROOT_CANDIDATE/include" -name "*.cpp" -type f)

        echo "  Copied $HEADER_COUNT header files and $CPP_COUNT support source files"

        # Update Makefile to point to the bundled headers
        if [ -f "$PACKAGE_DIR/Vtoplevel.mk" ]; then
            echo "Updating Makefile to use relative Verilator path..."
            sed -i.bak 's|^VERILATOR_ROOT\s*[?]*=\s*.*|VERILATOR_ROOT = $(shell pwd)/verilator_include/..|' "$PACKAGE_DIR/Vtoplevel.mk"
            rm -f "$PACKAGE_DIR/Vtoplevel.mk.bak" 2>/dev/null || true
        fi

        HAS_VERILATOR_HEADERS=true
    else
        echo "Warning: Unable to locate Verilator installation. Skipping header copy."
        echo "Hint: export VERILATOR_ROOT=/path/to/verilator or install Verilator in a standard path."
    fi
fi

# Generate README
if [ "$HAS_VERILATOR_HEADERS" == "true" ]; then
    VERILATOR_NOTE="\
Note: This bundle contains the Verilator headers. You do not need a system-wide Verilator installation.\n\
The Makefile has been updated to use the packaged headers.\n"
    VERILATOR_REQ="Included in this package"
else
    VERILATOR_NOTE="\
Note: This bundle does not include the Verilator headers. Install Verilator on the target system.\n\
Set the VERILATOR_ROOT environment variable to point to the installation directory.\n"
    VERILATOR_REQ="Must be installed on the system"
fi

cat > "$PACKAGE_DIR/README.txt" << EOF
cpp1 Packaging Overview
=======================

Mode: $PACKAGE_MODE
Timestamp: $(date)

Contents:
---------
- Vtoplevel: Executable
- Vtoplevel*.h: Header files
- Vtoplevel*.cpp: Source files
- Vtoplevel__ALL.a: Static library
- Vtoplevel.mk: Makefile
- Vtoplevel_classes.mk: Class definition Makefile
$VERILATOR_NOTE
Usage:
------
1. Extract the archive
2. Enter the extracted directory
3. Run the executable: ./Vtoplevel
4. Or rebuild: make -f Vtoplevel.mk

Requirements:
-------------
- C++ compiler (GCC/Clang)
- Standard C++ runtime libraries
- Verilator ($VERILATOR_REQ)

EOF

# Create archive
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
ARCHIVE_NAME="${PACKAGE_NAME}_${TIMESTAMP}.tar.gz"
ARCHIVE_PATH="../${ARCHIVE_NAME}"

echo "Creating archive: $ARCHIVE_PATH"
cd "$TEMP_DIR"
tar -czf "$SCRIPT_DIR/$ARCHIVE_NAME" "$PACKAGE_NAME"

# Clean up temporary directory
rm -rf "$TEMP_DIR"

echo ""
echo "Packaging complete!"
echo "Archive path: $ARCHIVE_PATH"
echo "File size: $(du -h "$SCRIPT_DIR/$ARCHIVE_NAME" | cut -f1)"
