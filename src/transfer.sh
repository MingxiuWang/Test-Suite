#!/bin/bash
working_directory=$(pwd)

# Define directories
success_dir="$working_directory/ae_nullptr_deref_tests"
failed_dir="$working_directory/ae_nullptr_deref_tests_failed"

# Create directories if they don't exist
mkdir -p "$success_dir"
mkdir -p "$failed_dir"

# List of failed test files (without extension)
failed_tests=(
    "array_2d_big_partial_null"
    "array_partial_nullptr"
    "char_ptr_loop_branch_nullptr"
    "int_ptr_loop_branch_nullptr"
    "nullptr_func"
    "recursive_safe"
    "recursive_simple"
    "recursive_simple_once"
    "recursive_struct"
    "safe_func_ptr"
    "struct_func_ptr"
)

# Convert array to set for easy lookup
declare -A failed_set
for test in "${failed_tests[@]}"; do
    failed_set["$test"]=1
done

# Process all .c files in both dirs
for dir in "$success_dir" "$failed_dir"; do
    for file in "$dir"/*.c; do
        [ -e "$file" ] || continue  # Skip if no files
        filename=$(basename "$file" .c)
        if [[ "${failed_set[$filename]}" ]]; then
            # File should be in failed_dir
            target="$failed_dir/$filename.c"
        else
            # File should be in success_dir
            target="$success_dir/$filename.c"
        fi

        if [[ "$file" != "$target" ]]; then
            echo "Moving $filename.c to $(dirname "$target")"
            mv "$file" "$target"
        fi
    done
done

echo "File organization complete."
