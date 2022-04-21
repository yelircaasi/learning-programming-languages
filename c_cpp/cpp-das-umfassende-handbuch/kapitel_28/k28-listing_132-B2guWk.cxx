using week = std::chrono::duration<int,
        std::ratio_multiply<std::ratio<7>,
            std::ratio_multiply<std::ratio<24>,hours::period>
        >
    >;

