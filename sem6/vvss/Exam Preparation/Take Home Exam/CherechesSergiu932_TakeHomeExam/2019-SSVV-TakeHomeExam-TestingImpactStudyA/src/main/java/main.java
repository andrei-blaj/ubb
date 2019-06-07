import java.util.ArrayList;
import java.util.List;

public class main {

    public static void main(String[] args){
        List<Emotion> list = new ArrayList<>();

        Emotion e1 = new Emotion("Sadness", EmotionType.Sadness);
        list.add(e1);
        Emotion e2 = new Emotion("Anger", EmotionType.Anger);
        list.add(e2);
        Emotion e3 = new Emotion("Fear", EmotionType.Fear);
        list.add(e3);
        Emotion e4 = new Emotion("Anger", EmotionType.Anger);
        list.add(e4);
        Emotion e5 = new Emotion("Sadness", EmotionType.Sadness);
        list.add(e5);
        Emotion e6 = new Emotion("Fear", EmotionType.Fear);
        list.add(e6);
        Emotion e7 = new Emotion("Fear", EmotionType.Fear);
        list.add(e7);

        ListEmotions listOfEmo = new ListEmotions(list);
        int anger, fear, sadness;

        anger = listOfEmo.howGivenManyEmotionTypeInListEmotions(EmotionType.Anger);
        fear = listOfEmo.howGivenManyEmotionTypeInListEmotions(EmotionType.Fear);
        sadness = listOfEmo.howGivenManyEmotionTypeInListEmotions(EmotionType.Sadness);

        System.out.println("Anger: " + anger);
        System.out.println("Fear: " + fear);
        System.out.println("Sadness: " + sadness);

        list = listOfEmo.predominantEmotion();

        System.out.println("\n\n");
        for (Emotion e: list) {
            System.out.println(e.getEmotionType() + " ");
        }

        listOfEmo.eliminateAllProvidedEmotion(EmotionType.Fear);
        fear = listOfEmo.howGivenManyEmotionTypeInListEmotions(EmotionType.Fear);
        System.out.println("\nFear: " + fear);
    }
}