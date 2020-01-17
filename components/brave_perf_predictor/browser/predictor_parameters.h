/* Copyright 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_PERF_PREDICTOR_BROWSER_PREDICTOR_PARAMETERS_H_
#define BRAVE_COMPONENTS_BRAVE_PERF_PREDICTOR_BROWSER_PREDICTOR_PARAMETERS_H_

/* This file is automatically generated, do not edit directly */

#include <string>
#include <map>
#include <vector>
#include <array>

namespace brave_perf_predictor {

const double model_intercept = 5.085562016132402;
const int feature_count = 214;
const std::array<double, feature_count> model_coefficients = {
0.12352367722740858,
-0.0,
-0.0,
0.0,
0.0,
0.0,
0.006892384968665546,
-0.0053006306015809974,
0.012808044375561328,
-0.022568426204584803,
0.0,
0.031262883891716595,
-0.008895304473470696,
0.0,
-0.012542033549705674,
-0.018165453504801546,
-0.008479435850304733,
0.0,
0.0,
0.002311112946961536,
0.04901700232714016,
0.0,
0.0,
-0.0,
0.03701018507587659,
0.014184085455013776,
-0.0,
0.10265583719234812,
0.05237925617436799,
0.0,
0.2561434657008117,
0.3954099722860754,
0.4241724431436048,
0.2554360194633748,
-0.0,
0.1110185928151764,
0.0,
0.0,
-0.0,
0.369424591785374,
-0.0621249125494256,
0.0,
-0.19227234809590055,
0.009790817504584938,
-0.0,
0.5981006783511988,
0.0,
-0.0,
0.0,
0.0,
-0.0,
-0.154225297347611,
0.5815994580458169,
0.07673442247118749,
-0.0,
0.07985643438092534,
0.0,
0.08301654084812561,
0.27974978085336505,
-0.3135774687124175,
0.0,
0.0,
0.0,
-0.0,
0.21721484909061123,
-0.0,
0.0,
-0.6603212899417499,
0.47382998205049726,
0.0,
0.031566994679697126,
0.0,
-0.0,
0.0,
0.0,
0.0,
0.41987279273153577,
-0.0,
-0.0,
0.0,
-0.15704804281369258,
0.05136354590905017,
-0.0,
-1.3967861171544764,
0.012049836970958124,
-0.16190555154009043,
0.0,
0.32236468110744876,
-0.10807182142138586,
0.0,
0.28113499778312084,
0.347455093844389,
0.0,
-0.0,
0.21577214682210177,
-0.0,
0.0,
-0.3494463283215819,
-0.15598019593473778,
0.2937099798752649,
-0.0,
-0.0,
-0.6670081562284095,
0.03155616836841969,
-0.0,
-0.0,
-0.0,
-0.4821830747864856,
-0.1060109448038188,
0.0,
0.0,
0.18025872807868917,
-0.0,
0.059651718175110925,
0.15412094403273932,
0.0,
0.0,
0.4104485276968183,
-0.0,
-0.0,
-0.0573642521280568,
-0.0183387630905243,
-0.0,
0.08825537070503531,
-0.0,
0.3576615077317695,
-0.0,
0.20454045632867554,
-0.0,
-0.22669760740718553,
0.3391651045388519,
0.40841054414438194,
3.320355416478889e-05,
-0.0,
0.009846843806251981,
0.6879938701965732,
-0.09809945092041333,
0.0,
0.0,
0.0,
0.24660181712712595,
0.0,
0.0,
0.2971937705828685,
-0.0,
0.00042832988368958795,
0.0011714853122736216,
0.3681970714031466,
0.0,
-0.4757811965402313,
-0.48264457834902585,
-0.0,
-0.14897936787284055,
-0.0,
0.0,
0.0,
-0.06864524030396776,
0.0,
0.0,
0.0,
-0.0,
-0.0,
-0.0,
-0.0,
-0.0,
-0.0939514698836343,
-0.17375737654279771,
0.4280298407194896,
0.07921243395532432,
0.0,
0.0,
0.002297138241541185,
-0.0,
-0.0,
-0.0,
-0.01300337447750894,
-0.0,
0.0643992239129706,
0.19270927069891977,
-0.40965167510194395,
-0.0,
-0.0,
-0.12522557448112873,
0.0,
0.0,
0.07914189703224955,
0.030383389451194256,
-0.0,
0.03990905584174161,
1.157147484387678,
0.0,
-0.0,
0.0,
0.0,
0.013087405412848738,
-0.0,
0.17464108300530065,
0.25197880082746205,
0.0,
-0.09217632122309656,
0.0,
0.0,
0.0,
-0.0,
-0.0,
-0.13491648330155384,
-0.0,
-0.03688074309361575,
-0.058518504088209695,
0.0,
-0.0,
-0.03592820829466529,
-0.3346781157893913,
-0.0
};

const unsigned int standardise_feat_count = 24;

const std::array<double, standardise_feat_count> standardise_feat_means = {
11.155786350148368,
1016.2856083086053,
1902.963649851632,
1181.3004451038576,
717.0712166172107,
1987.0066765578636,
2.4109792284866467,
61992.13946587537,
4.561572700296736,
149840.9243323442,
35.32047477744807,
955033.309347181,
0.13427299703264095,
15261.759643916914,
8.208456973293769,
246940.89243323443,
23.16765578635015,
495043.6083086053,
6.2974777448071215,
103430.64317507419,
48.926557863501486,
974124.4658753709,
80.10089020771514,
2027543.2767062315
};

const std::array<double, standardise_feat_count> standardise_feat_scale = {
12.073811227476089,
926.9436100765363,
1793.6185415841003,
979.2250013928962,
779.8742124298378,
1919.1239982290276,
2.102760215714359,
87820.15974403986,
3.575166724949133,
280657.60316361417,
36.691628938982134,
2053276.1547853663,
3.22967240113416,
205275.94312591644,
14.301294363369117,
2396278.961167811,
24.39484351361213,
432881.54561501107,
10.733199259238853,
129287.31378334873,
52.84516132149959,
2258334.3952942668,
57.77650764802925,
3333644.900695055
};

const std::array<std::string, feature_count>  feature_sequence = {
  "adblockRequests",
  "metrics.firstMeaningfulPaint",
  "metrics.interactive",
  "metrics.observedDomContentLoaded",
  "metrics.observedFirstVisualChange",
  "metrics.observedLoad",
  "resources.document.requestCount",
  "resources.document.size",
  "resources.font.requestCount",
  "resources.font.size",
  "resources.image.requestCount",
  "resources.image.size",
  "resources.media.requestCount",
  "resources.media.size",
  "resources.other.requestCount",
  "resources.other.size",
  "resources.script.requestCount",
  "resources.script.size",
  "resources.stylesheet.requestCount",
  "resources.stylesheet.size",
  "resources.third-party.requestCount",
  "resources.third-party.size",
  "resources.total.requestCount",
  "resources.total.size",
  "thirdParties.Google Analytics.blocked",
  "thirdParties.Facebook.blocked",
  "thirdParties.Google CDN.blocked",
  "thirdParties.Twitter.blocked",
  "thirdParties.Other Google APIs/SDKs.blocked",
  "thirdParties.Scorecard Research.blocked",
  "thirdParties.Sortable.blocked",
  "thirdParties.Google/Doubleclick Ads.blocked",
  "thirdParties.Adobe Tag Manager.blocked",
  "thirdParties.Google Tag Manager.blocked",
  "thirdParties.Chartbeat.blocked",
  "thirdParties.Amazon Ads.blocked",
  "thirdParties.Salesforce.blocked",
  "thirdParties.Adobe Test & Target.blocked",
  "thirdParties.YouTube.blocked",
  "thirdParties.Outbrain.blocked",
  "thirdParties.Tumblr.blocked",
  "thirdParties.WordPress.blocked",
  "thirdParties.Bing Ads.blocked",
  "thirdParties.New Relic.blocked",
  "thirdParties.JuicyAds.blocked",
  "thirdParties.Audience 360.blocked",
  "thirdParties.Revcontent.blocked",
  "thirdParties.Pubmatic.blocked",
  "thirdParties.AppNexus.blocked",
  "thirdParties.SpotXchange.blocked",
  "thirdParties.AOL / Oath / Verizon Media.blocked",
  "thirdParties.Amazon Web Services.blocked",
  "thirdParties.LoopMe.blocked",
  "thirdParties.Quantcast.blocked",
  "thirdParties.Click4Assistance.blocked",
  "thirdParties.Hotjar.blocked",
  "thirdParties.Snapchat.blocked",
  "thirdParties.jQuery CDN.blocked",
  "thirdParties.Segment.blocked",
  "thirdParties.Usabilla.blocked",
  "thirdParties.Nativo.blocked",
  "thirdParties.Sharethrough.blocked",
  "thirdParties.Twitter Online Conversion Tracking.blocked",
  "thirdParties.BounceX.blocked",
  "thirdParties.Integral Ad Science.blocked",
  "thirdParties.Rubicon Project.blocked",
  "thirdParties.Index Exchange.blocked",
  "thirdParties.Sentry.blocked",
  "thirdParties.Cloudflare CDN.blocked",
  "thirdParties.VigLink.blocked",
  "thirdParties.Optimizely.blocked",
  "thirdParties.Ensighten.blocked",
  "thirdParties.Criteo.blocked",
  "thirdParties.Nielsen NetRatings SiteCensus.blocked",
  "thirdParties.Cookie-Script.com.blocked",
  "thirdParties.Rackspace.blocked",
  "thirdParties.Adobe TypeKit.blocked",
  "thirdParties.Stripe.blocked",
  "thirdParties.Trust Pilot.blocked",
  "thirdParties.Polyfill service.blocked",
  "thirdParties.Affiliate Window.blocked",
  "thirdParties.FontAwesome CDN.blocked",
  "thirdParties.Bootstrap CDN.blocked",
  "thirdParties.Auto Link Maker.blocked",
  "thirdParties.Embedly.blocked",
  "thirdParties.JSDelivr CDN.blocked",
  "thirdParties.OneSignal.blocked",
  "thirdParties.The Trade Desk.blocked",
  "thirdParties.Instagram.blocked",
  "thirdParties.PayPal.blocked",
  "thirdParties.Taboola.blocked",
  "thirdParties.Opentag.blocked",
  "thirdParties.Brightcove.blocked",
  "thirdParties.VWO.blocked",
  "thirdParties.Rambler.blocked",
  "thirdParties.Media Math.blocked",
  "thirdParties.Google Maps.blocked",
  "thirdParties.Unpkg.blocked",
  "thirdParties.Yandex Share.blocked",
  "thirdParties.Yandex Metrica.blocked",
  "thirdParties.Yandex CDN.blocked",
  "thirdParties.Amplitude Mobile Analytics.blocked",
  "thirdParties.Yahoo!.blocked",
  "thirdParties.Yandex Ads.blocked",
  "thirdParties.piano.blocked",
  "thirdParties.Moat.blocked",
  "thirdParties.Parse.ly.blocked",
  "thirdParties.Unruly Media.blocked",
  "thirdParties.Skimbit.blocked",
  "thirdParties.ZenDesk.blocked",
  "thirdParties.Silverpop.blocked",
  "thirdParties.AddThis.blocked",
  "thirdParties.Polldaddy.blocked",
  "thirdParties.Dailymotion.blocked",
  "thirdParties.Disqus.blocked",
  "thirdParties.Alexa.blocked",
  "thirdParties.Mailchimp.blocked",
  "thirdParties.Tealium.blocked",
  "thirdParties.LiveChat.blocked",
  "thirdParties.DemandBase.blocked",
  "thirdParties.Tencent.blocked",
  "thirdParties.Oracle Recommendations On Demand.blocked",
  "thirdParties.Mixpanel.blocked",
  "thirdParties.PerimeterX Bot Defender.blocked",
  "thirdParties.Evidon.blocked",
  "thirdParties.Media.net.blocked",
  "thirdParties.Ghostery Enterprise.blocked",
  "thirdParties.LongTail Ad Solutions.blocked",
  "thirdParties.Sailthru.blocked",
  "thirdParties.Marketplace Web Service.blocked",
  "thirdParties.Pinterest.blocked",
  "thirdParties.BrightTag / Signal.blocked",
  "thirdParties.mPulse.blocked",
  "thirdParties.ForeSee.blocked",
  "thirdParties.Permutive.blocked",
  "thirdParties.FirstImpression.blocked",
  "thirdParties.Connatix.blocked",
  "thirdParties.Media Management Technologies.blocked",
  "thirdParties.Mobify.blocked",
  "thirdParties.Yieldify.blocked",
  "thirdParties.Crazy Egg.blocked",
  "thirdParties.SurveyMonkey.blocked",
  "thirdParties.Touch Commerce.blocked",
  "thirdParties.RichRelevance.blocked",
  "thirdParties.Reevoo.blocked",
  "thirdParties.Micropat.blocked",
  "thirdParties.Playbuzz.blocked",
  "thirdParties.Po.st.blocked",
  "thirdParties.Fastly.blocked",
  "thirdParties.eBay.blocked",
  "thirdParties.TRUSTe.blocked",
  "thirdParties.Qualtrics.blocked",
  "thirdParties.Aggregate Knowledge.blocked",
  "thirdParties.Digioh.blocked",
  "thirdParties.Gigya.blocked",
  "thirdParties.Crowd Control.blocked",
  "thirdParties.LinkedIn Ads.blocked",
  "thirdParties.Riskified.blocked",
  "thirdParties.BlueKai.blocked",
  "thirdParties.AMP.blocked",
  "thirdParties.eXelate.blocked",
  "thirdParties.Captify Media.blocked",
  "thirdParties.Hola Networks.blocked",
  "thirdParties.Polar Mobile Group.blocked",
  "thirdParties.Apester.blocked",
  "thirdParties.StreamRail.blocked",
  "thirdParties.SpringServer.blocked",
  "thirdParties.Monetate.blocked",
  "thirdParties.Adobe Scene7.blocked",
  "thirdParties.Opta.blocked",
  "thirdParties.FLXone.blocked",
  "thirdParties.Sift Science.blocked",
  "thirdParties.Accuweather.blocked",
  "thirdParties.Lucky Orange.blocked",
  "thirdParties.AWeber.blocked",
  "thirdParties.Salesforce.com.blocked",
  "thirdParties.Wistia.blocked",
  "thirdParties.Histats.blocked",
  "thirdParties.ShareThis.blocked",
  "thirdParties.Adyoulike.blocked",
  "thirdParties.Pusher.blocked",
  "thirdParties.PERFORM.blocked",
  "thirdParties.Pingdom RUM.blocked",
  "thirdParties.Cloudflare.blocked",
  "thirdParties.Hubspot.blocked",
  "thirdParties.Curalate.blocked",
  "thirdParties.Decibel Insight.blocked",
  "thirdParties.Mouseflow.blocked",
  "thirdParties.Symantec.blocked",
  "thirdParties.Proper Media.blocked",
  "thirdParties.Vimeo.blocked",
  "thirdParties.LivePerson.blocked",
  "thirdParties.Clicktale.blocked",
  "thirdParties.iPerceptions.blocked",
  "thirdParties.Sekindo.blocked",
  "thirdParties.OpenX.blocked",
  "thirdParties.Teads.blocked",
  "thirdParties.sovrn.blocked",
  "thirdParties.GumGum.blocked",
  "thirdParties.Microsoft Hosted Libs.blocked",
  "thirdParties.Vox Media.blocked",
  "thirdParties.Concert.blocked",
  "thirdParties.Xaxis.blocked",
  "thirdParties.unpkg.blocked",
  "thirdParties.Maxymiser.blocked",
  "thirdParties.Kaltura Video Platform.blocked",
  "thirdParties.SoundCloud.blocked",
  "thirdParties.Kargo.blocked",
  "thirdParties.TripleLift.blocked",
  "thirdParties.Trip Advisor.blocked",
  "thirdParties.Cloudinary.blocked",
  "thirdParties.Tawk.to.blocked",
  "thirdParties.Klevu Search.blocked",
  "thirdParties.Yandex APIs.blocked",
};

struct stdfactor {
    double mean, scale;
};

const std::map<std::string, stdfactor > stdfactor_map = {
  {
    "adblockRequests",
    { 11.155786350148368, 12.073811227476089 }
  },
  {
    "metrics.firstMeaningfulPaint",
    { 1016.2856083086053, 926.9436100765363 }
  },
  {
    "metrics.interactive",
    { 1902.963649851632, 1793.6185415841003 }
  },
  {
    "metrics.observedDomContentLoaded",
    { 1181.3004451038576, 979.2250013928962 }
  },
  {
    "metrics.observedFirstVisualChange",
    { 717.0712166172107, 779.8742124298378 }
  },
  {
    "metrics.observedLoad",
    { 1987.0066765578636, 1919.1239982290276 }
  },
  {
    "resources.document.requestCount",
    { 2.4109792284866467, 2.102760215714359 }
  },
  {
    "resources.document.size",
    { 61992.13946587537, 87820.15974403986 }
  },
  {
    "resources.font.requestCount",
    { 4.561572700296736, 3.575166724949133 }
  },
  {
    "resources.font.size",
    { 149840.9243323442, 280657.60316361417 }
  },
  {
    "resources.image.requestCount",
    { 35.32047477744807, 36.691628938982134 }
  },
  {
    "resources.image.size",
    { 955033.309347181, 2053276.1547853663 }
  },
  {
    "resources.media.requestCount",
    { 0.13427299703264095, 3.22967240113416 }
  },
  {
    "resources.media.size",
    { 15261.759643916914, 205275.94312591644 }
  },
  {
    "resources.other.requestCount",
    { 8.208456973293769, 14.301294363369117 }
  },
  {
    "resources.other.size",
    { 246940.89243323443, 2396278.961167811 }
  },
  {
    "resources.script.requestCount",
    { 23.16765578635015, 24.39484351361213 }
  },
  {
    "resources.script.size",
    { 495043.6083086053, 432881.54561501107 }
  },
  {
    "resources.stylesheet.requestCount",
    { 6.2974777448071215, 10.733199259238853 }
  },
  {
    "resources.stylesheet.size",
    { 103430.64317507419, 129287.31378334873 }
  },
  {
    "resources.third-party.requestCount",
    { 48.926557863501486, 52.84516132149959 }
  },
  {
    "resources.third-party.size",
    { 974124.4658753709, 2258334.3952942668 }
  },
  {
    "resources.total.requestCount",
    { 80.10089020771514, 57.77650764802925 }
  },
  {
    "resources.total.size",
    { 2027543.2767062315, 3333644.900695055 }
  },
};

}  // namespace brave_perf_predictor

#endif  // BRAVE_COMPONENTS_BRAVE_PERF_PREDICTOR_BROWSER_PREDICTOR_PARAMETERS_H_