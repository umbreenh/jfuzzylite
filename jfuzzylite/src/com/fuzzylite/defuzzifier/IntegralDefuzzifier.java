/*   Copyright 2013 Juan Rada-Vilela

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
package com.fuzzylite.defuzzifier;

import com.fuzzylite.FuzzyLite;

/**
 *
 * @author jcrada
 */
//TODO: check  http://en.wikipedia.org/wiki/Adaptive_quadrature
public abstract class IntegralDefuzzifier extends Defuzzifier {

    protected int resolution = FuzzyLite.getResolution();

    public IntegralDefuzzifier() {
    }

    public IntegralDefuzzifier(int resolution) {
        this.resolution = resolution;
    }

    public int getResolution() {
        return resolution;
    }

    public void setResolution(int resolution) {
        this.resolution = resolution;
    }
}
