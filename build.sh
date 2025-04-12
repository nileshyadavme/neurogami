#!/bin/bash

PROJECT_NAME="neurogami"
BUILD_DIR="build"

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[1;34m"
NC="\033[0m" # No Color

echo -e "${BLUE}🚧 Building project: ${PROJECT_NAME}...${NC}"

# Step 1: Create build directory if not exists
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}

# Step 2: Run CMake configuration
if cmake ..; then
    echo -e "${GREEN}✅ CMake configured successfully.${NC}"
else
    echo -e "${RED}❌ CMake configuration failed.${NC}"
    exit 1
fi

# Step 3: Build project
if cmake --build .; then
    echo -e "${GREEN}🎉 Build successful!${NC}"
else
    echo -e "${RED}❌ Build failed.${NC}"
    exit 1
fi

# Step 4: Optional - run the output binary
if [[ -f "./${PROJECT_NAME}" ]]; then
    echo -e "${BLUE}🚀 Running ${PROJECT_NAME}...${NC}"
    echo "-----------------------------------"
    ./${PROJECT_NAME}
    echo "-----------------------------------"
else
    echo -e "${RED}❌ Executable not found: ${PROJECT_NAME}${NC}"
fi
