#include <opencv2/opencv.hpp> // Main OpenCV header
#include <iostream>           // For console output

int main(int argc, char** argv) { // THIS LINE IS CORRECTED
    // Check if an image path was provided as a command-line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <Image_Path>" << std::endl;
        return -1; // Indicate an error
    }

    // Load the image from the provided path (pw removed from here)
    // imread() returns a cv::Mat object, which is OpenCV's way of storing images
    cv::Mat image = cv::imread(argv[1]);

    // Check if the image was loaded successfully
    if (image.empty()) { // image.empty() returns true if the image is not loaded
        std::cerr << "Error: Could not open or find the image: " << argv[1] << std::endl;
        return -1; // Indicate an error
    }

    // Display the image in a window
    // imshow() creates a window with the given name and displays the image
    cv::imshow("Loaded Image", image);

    // Wait for a key press indefinitely
    // waitKey(0) waits for any key press to close the window
    // If you put a positive number (e.g., waitKey(5000)), it waits for that many milliseconds
    cv::waitKey(0);

    // Destroy all OpenCV windows
    // It's good practice to clean up
    cv::destroyAllWindows();

    std::cout << "Image displayed successfully. Exiting." << std::endl;

    return 0; // Indicate success
}