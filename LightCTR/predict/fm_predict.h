//
//  fm_predict.hpp
//  LightCTR
//
//  Created by SongKuangshi on 2017/9/24.
//  Copyright © 2017年 SongKuangshi. All rights reserved.
//

#ifndef fm_predict_h
#define fm_predict_h

#include <stdio.h>
#include "../fm_algo_abst.h"
#include "../util/evaluator.h"
#include "../util/activations.h"

class FM_Predict {
public:
    FM_Predict(FM_Algo_Abst* p, string _testDataPath, bool with_valid_label) {
        this->fm = p;
        loadDataRow(_testDataPath, with_valid_label);
    }
    ~FM_Predict() {
        
    }
    void Predict(string);
    void loadDataRow(string, bool);
    
private:
    FM_Algo_Abst* fm;
    size_t test_dataRow_cnt;
    vector<vector<FMFeature> > test_dataSet;
    vector<int> test_label;
    
    Sigmoid sigmoid;
};

#endif /* fm_predict_h */
