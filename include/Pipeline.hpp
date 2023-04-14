/*
** EPITECH PROJECT, 2022
** pipeline
** File description:
** Pipeline.hpp
*/

#ifndef PIPELINE_HPP
    #define PIPELINE_HPP
    #include <vector>
    #include <stddef.h>
    #include <functional>
    #include <initializer_list>
    #include <array>
    #include <string>
    #include <thread>

namespace pp {
    /**
     * @brief Utility class to automatize calling a series of functions.
     * Note: Most of the time, the user is better of using a simple
     * std::vector<std::function<...>>. Use it if you need to change
     * the order of the functions at runtime or if you need to add
     * functions at runtime.
     *
     * @tparam ArgType
     * @tparam Args
     */
    template <typename ArgType, typename... Args>
    class Pipeline {
        public:
            template <typename...> struct container {};

            Pipeline() {}
            /**
             * @brief Construct a new Pipeline from a list of functions.
             *
             * @param funcs
             */
            Pipeline(std::initializer_list<ArgType (*)(ArgType, Args ...)> funcs) {
                for (const auto& func : funcs) {
                    _funcs.push_back(func);
                }
            }

            /**
             * @brief Adds a function at the end of the pipeline.
             *
             * @param fun
             */
            void push_back(ArgType (*fun)(ArgType, Args...)) {
                _funcs.push_back(fun);
            }

            /**
             * @brief Adds a function at the beginning of the pipeline.
             *
             * @param fun
             */
            void push_front(ArgType (*fun)(ArgType, Args...)) {
                _funcs.insert(_funcs.begin(), fun);
            }

            /**
             * @brief AErases a function at the rear of the pipeline.
             *
             * @param fun
             * @param index
             */
            void pop_back() {
                _funcs.pop_back();
            }

            /**
             * @brief Erases a function at the front of the pipeline.
             *
             * @param fun
             * @param index
             */
            void pop_front() {
                _funcs.erase(_funcs.begin());
            }

            /**
             * @brief Erases all functions from the pipeline.
             *
             */
            void clear() {
                _funcs.clear();
            }

            /**
             * @brief Erases a function at the given index.
             *
             * @param index
             */
            void erase(size_t index) {
                _funcs.erase(_funcs.begin() + index);
            }

            /**
             * @brief Runs the pipeline, calling all function with the result of
             * the previous function.
             *
             * @param mainArg
             * @param args
             * @return ArgType
             */
            ArgType run(ArgType mainArg, Args... args) {
                ArgType tmp = mainArg;

                for (auto &func : _funcs) {
                    tmp = func(tmp, args...);
                }
                return tmp;
            }

            /**
             * @brief Runs the pipeline in parallel, calling all function with the result of
             * the previous function.
             *
             * @param mainArg
             * @param args
             * @return ArgType
             */
            static std::vector<ArgType> runParallel(std::vector<Pipeline<ArgType, Args...>> pipelines,
                ArgType mainArg, ArgType (*callback)(Pipeline<ArgType, Args...>, ArgType))
            {
                std::vector<ArgType> results(pipelines.size());
                std::vector<std::thread> threads;

                for (size_t i = 0; i < pipelines.size(); i++) {
                    threads.push_back(std::thread([i, &pipelines, &results, mainArg, callback]() {
                        results[i] = callback(pipelines[i], mainArg);
                    }));
                }
                for (auto &thread : threads)
                    thread.join();
                return results;
            }

        protected:
        private:
            std::vector<ArgType (*)(ArgType, Args...)> _funcs;
    };

}

#endif // PIPELINE_HPP
