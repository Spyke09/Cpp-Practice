template<typename T>
T default_value{};

int main() {
    [[maybe_unused]] auto x = default_value<int>;
    default_value<double> = 30.5;
}