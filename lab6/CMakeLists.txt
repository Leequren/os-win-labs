cmake_minimum_required(VERSION 3.10)
project(lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_subdirectory(server)
add_subdirectory(client)

# add_custom_target(run
#     # Запуск сервера
#     COMMAND ${CMAKE_COMMAND} -E echo "Starting server..."
#     COMMAND powershell DEPENDS server client -Command "Start-Process -FilePath '${CMAKE_BINARY_DIR}/lab6/server/server.exe' -NoNewWindow" 
    
#     # Запуск клиента
#     COMMAND ${CMAKE_COMMAND} -E echo "Starting client after a delay..."
#     COMMAND powershell DEPENDS server client -Command "Start-Sleep -Seconds 1; Start-Process -FilePath '${CMAKE_BINARY_DIR}/lab6/client/client.exe' -NoNewWindow"
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
# )

add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E echo "Starting server..."
    COMMAND powershell -Command "Start-Process -FilePath '${CMAKE_BINARY_DIR}/lab6/server/server.exe' -NoNewWindow" DEPENDS server
    COMMAND ${CMAKE_COMMAND} -E echo "Starting client after a delay..."
    COMMAND powershell -Command "Start-Sleep -Seconds 1; Start-Process -FilePath '${CMAKE_BINARY_DIR}/lab6/client/client.exe' -NoNewWindow" DEPENDS client
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
