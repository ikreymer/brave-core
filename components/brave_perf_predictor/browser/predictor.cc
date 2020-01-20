/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_perf_predictor/browser/predictor.h"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>

#include "base/logging.h"

namespace brave_perf_predictor {

namespace {

bool StandardiseFeatsNoOutliers(
    std::array<double, standardise_feat_count>* features,
    const std::array<double, standardise_feat_count>& means,
    const std::array<double, standardise_feat_count>& scale) {
  for (unsigned int i = 0; i < standardise_feat_count; i++) {
    features->at(i) = (features->at(i) - means[i]) / scale[i];
  }
  double outlier_threshold = 6;
  for (unsigned int i = 0; i < standardise_feat_count; i++) {
    if (features->at(i) > outlier_threshold ||
        features->at(i) < -outlier_threshold) {
      VLOG(2) << "Outlier feature " << feature_sequence.at(i) << " with value "
              << features->at(i);
      return true;
    }
  }
  return false;
}

}  // namespace

double Predict(const std::array<double, feature_count>& features) {
  // Standardise numeric features
  std::array<double, standardise_feat_count> numeric_features;
  std::copy(features.begin(), features.begin() + standardise_feat_count,
            numeric_features.begin());
  bool has_outliers = StandardiseFeatsNoOutliers(
      &numeric_features, standardise_feat_means, standardise_feat_scale);
  if (has_outliers) {
    VLOG(2) << "Feature set has outliers, return 0";
    return 0;
  }

  // Create a new feature vector to include all features
  std::array<double, feature_count> standardised_features;
  std::move(numeric_features.begin(), numeric_features.end(),
            standardised_features.begin());
  // Just copy the rest of the features as-is
  std::copy(features.begin() + standardise_feat_count, features.end(),
            standardised_features.begin() + standardise_feat_count);

  // Calculate the prediction
  double log_prediction = std::inner_product(
      standardised_features.begin(), standardised_features.end(),
      model_coefficients.begin(), model_intercept);
  // We know the target is log-scaled but care about the absolute value
  return std::pow(10, log_prediction);
}

double Predict(const std::unordered_map<std::string, double>& features) {
  std::array<double, feature_count> feature_vector{};
  for (unsigned int i = 0; i < feature_count; i++) {
    auto it = features.find(feature_sequence[i]);
    if (it != features.end())
      feature_vector[i] = it->second;
  }
  return Predict(feature_vector);
}

}  // namespace brave_perf_predictor
