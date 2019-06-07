import java.lang.reflect.Array;
import java.util.*;


public class ListEmotions {

    private List<Emotion> lstEmotions;

    public ListEmotions(List<Emotion> newLstEmotions){
        this.lstEmotions = newLstEmotions;
    }

    public int getNumberOfEmotions(){
        return lstEmotions.size();
    }

    // Task A_1
    // return the number of emotion of the given EmotionType et
    // Remark: No test cases are going to be created.
    public int howGivenManyEmotionTypeInListEmotions(EmotionType et){
        int nJE=0;

        for (Emotion e: lstEmotions) {
            if (e.getEmotionType().equals(et)){
                nJE += 1;
            }
        }

        return nJE;
    }



    // Task A_2
    // return the list of predominant emotions
    // Remark: Create a set of test cases to assess the correctness of your code.
    //         Create a class to test this method, several test cases are needed.
    //         One sample test case is provided in cladd Test_ListEmotions.
    public List<Emotion> predominantEmotion(){
        List<Emotion> lstEPredominant = new ArrayList<Emotion>();
        //Add code here

        Map<EmotionType, Integer> emotionMap = new HashMap<>();

        emotionMap.put(EmotionType.Joy, 0);
        emotionMap.put(EmotionType.Anger, 0);
        emotionMap.put(EmotionType.Sadness, 0);
        emotionMap.put(EmotionType.Disgust, 0);
        emotionMap.put(EmotionType.Fear, 0);

        for (Emotion e: this.lstEmotions) {
            emotionMap.put(e.getEmotionType(), emotionMap.get(e.getEmotionType()) + 1);
        }

        int max = 0;
        List<EmotionType> et = new ArrayList<>();

        for (Map. Entry<EmotionType, Integer> entry : emotionMap.entrySet()) {
            if(entry.getValue() > max){
                max = entry.getValue();
            }

        }

        if (max == 0){
            max = -1;
        }

        for (Map. Entry<EmotionType, Integer> entry : emotionMap.entrySet()) {
            if(entry.getValue() == max){
                et.add(entry.getKey());
            }

        }

        for (Emotion e: lstEmotions) {

            if (et.contains(e.getEmotionType())){
                lstEPredominant.add(e);
            }

        }
        return  lstEPredominant;
    }

    // Task A_3
    // Eliminate the emotions that are of given type EmotionType et
    // Remark: A set of test cases to assess the correctness of your code is provided.
    //         A class to test this method was created, several test cases were added.
    //         Use the test cases to check for your code.
    public void eliminateAllProvidedEmotion(EmotionType et){
        //Add code here
        //Added code here

        List<Emotion> auxList = new ArrayList<>();

        for (Emotion e: this.lstEmotions) {
            if (e.getEmotionType() != et){
                auxList.add(e);
            }
        }

        this.lstEmotions = auxList;
    }
}
