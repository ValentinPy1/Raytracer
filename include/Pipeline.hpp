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
    template <typename ArgType, typename... Args>
    class Pipeline {
        public:
            template <typename...> struct container {};

            Pipeline() {}
            Pipeline(std::initializer_list<ArgType (*)(ArgType, Args ...)> funcs) {
                for (const auto& func : funcs) {
                    _funcs.push_back(func);
                }
            }

            void push_back(ArgType (*fun)(ArgType, Args...)) {
                _funcs.push_back(fun);
            }

            void push_front(ArgType (*fun)(ArgType, Args...)) {
                _funcs.insert(_funcs.begin(), fun);
            }

            void pop_back() {
                _funcs.pop_back();
            }

            void pop_front() {
                _funcs.erase(_funcs.begin());
            }

            void clear() {
                _funcs.clear();
            }

            void erase(size_t index) {
                _funcs.erase(_funcs.begin() + index);
            }

            ArgType run(ArgType mainArg, Args... args) {
                ArgType tmp = mainArg;

                for (auto &func : _funcs) {
                    tmp = func(tmp, args...);
                }
                return tmp;
            }

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
