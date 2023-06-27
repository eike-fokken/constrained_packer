

extern "C" {

int repack_with_given_amounts(
    char const **names, int number_of_names, float const *demands,
    int number_of_demands, float const *package_sizes,
    int number_of_package_sizes, int *amounts_per_package_size,
    int number_of_amounts_per_package_size,
    int **out_packed_amounts_per_package_size_and_group);
}
