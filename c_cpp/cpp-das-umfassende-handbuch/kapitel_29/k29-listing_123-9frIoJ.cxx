std::shared_ptr<BigData> bigData{};
BigData& getBigData() {
    if(!bigData) bigData.reset(new BigData{});
    return *bigData;
}
int useBigData() {
    auto bigData = getBigData();
    // bigData->...
}

