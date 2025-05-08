import nltk
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

nltk.download('punkt')

# Movie booking-related corpus
corpus = {
    "hello": "Hi there! Welcome to MovieBot. How can I assist you today?",
    "hi": "Hello! Need help booking a movie?",
    "book a ticket": "Sure! Which movie would you like to watch?",
    "i want to book a movie": "Absolutely! Please tell me the movie name.",
    "what movies are playing": "Here are some movies currently showing: Dune 2, Avengers, Oppenheimer, and Barbie.",
    "show me showtimes": "Sure! Please specify the movie and your preferred date.",
    "what are the showtimes for dune 2": "Dune 2 is playing at 1:00 PM, 4:30 PM, and 8:00 PM today.",
    "how much is a ticket": "Tickets usually cost between $8 and $15 depending on the time and type of seat.",
    "can i select my seat": "Yes, you can choose your seat from the seating layout during booking.",
    "is 3d available": "Yes, 3D is available for select movies. Please mention the title.",
    "cancel my booking": "Please provide your booking ID to proceed with the cancellation.",
    "thank you": "You're welcome! Enjoy your movie.",
    "bye": "Goodbye! Hope to see you again soon.",
    "help": "I can help you book tickets, show movies, and cancel bookings.",
    "default": "I'm sorry, I didn't get that. Could you rephrase?"
}

corpus_keys = list(corpus.keys())
vectorizer = TfidfVectorizer()
tfidf = vectorizer.fit_transform(corpus_keys)

def chatbot_response(user_input):
    user_input = user_input.lower()
    user_vec = vectorizer.transform([user_input])
    similarity = cosine_similarity(user_vec, tfidf)
    idx = similarity.argmax()
    score = similarity[0][idx]

    if score < 0.2:
        return corpus["default"]
    return corpus[corpus_keys[idx]]

print("MovieBot: Hello! Type 'bye' to exit.")
while True:
    user_input = input("You: ")
    if user_input.lower() == "bye":
        print("MovieBot:", corpus["bye"])
        break
    print("MovieBot:", chatbot_response(user_input))
